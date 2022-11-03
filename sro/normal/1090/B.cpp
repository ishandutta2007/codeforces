/*----------------by syr----------------*/
/*
  -----  -----  -----
  |   |  |---|    _/
  |   |  | \_    /
  -----  |   \  -----

  |---\  \   /  |\  /|
  |   |   \_/   | \/ |
  |   |   / \   |    |
  |---/  /   \  |    |
*/
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<limits>
#include<list>
#include<map>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<sstream>
#include<string>
#include<time.h>
#include<utility>
#include<vector>

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;

const int INF=1e9+7;
const string BEGIN="\\begin{thebibliography}{99}";
const string REFERENCE="\\cite";
const string END="\\end{thebibliography}";
const int maxn=105;

int ord[maxn];
string s;
string bibli[maxn];
vector<string> refer;

void getRef(string word){
//	cout<<word<<endl;
	string hd="",ret="";
	FOR(i,0,min((int)word.size(),5)) hd+=word[i];
//	cout<<hd<<endl;
	if(hd!=REFERENCE) return;
	for(int i=6;i<word.size()&&word[i]!='}';++i) ret+=word[i];
	refer.PB(ret);
	return;
}

string getBib(string bib){
	string ret="";
	for(int i=9;bib[i]!='}';++i) ret+=bib[i];
	return ret;
}

int main(){
//	freopen("output.txt","w",stdout);
	for(getline(cin,s);s!=BEGIN;getline(cin,s)){
		stringstream strin;
		string word;
		strin<<s;
		while(strin>>word){
			getRef(word);
		}
	}
//	FOR(i,0,refer.size()) cout<<refer[i]<<endl;
	int tot=0;
	for(getline(cin,bibli[tot]);bibli[tot]!=END;getline(cin,bibli[tot])){
		string bib=getBib(bibli[tot]);
//		cout<<bib<<endl;
		FOR(j,0,refer.size()){
			if(refer[j]==bib) ord[j]=tot;
		}
		tot++;
	}
	FOR(i,0,refer.size()){
		if(ord[i]!=i){
			puts("Incorrect");
			cout<<BEGIN<<endl;
			FOR(j,0,refer.size()){
				cout<<bibli[ord[j]]<<endl;
			}
			cout<<END<<endl;
			return 0;
		}
	}
	puts("Correct");
	return 0;
}

/*
The most famous characters of Pushkins works are Onegin \cite{onegin},
Dubrovsky \cite{dubrovsky} and Tsar Saltan \cite{saltan}.
\begin{thebibliography}{99}
\bibitem{saltan} A.S.Pushkin. The Tale of Tsar Saltan. 1832.
\bibitem{onegin} A.S.Pushkin. Eugene Onegin. 1831.
\bibitem{dubrovsky} A.S.Pushkin. Dubrovsky. 1841.
\end{thebibliography}
*/