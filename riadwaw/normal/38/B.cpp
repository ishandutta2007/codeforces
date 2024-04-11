#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <complex>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
typedef double ld;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
	freopen("input", "r", stdin);
	//freopen("output","w",stdout);
#endif
	solve();
    return 0;
}
pair<int,int> h[]={mp(1,2),mp(1,-2),mp(-1,2),mp(-1,-2),mp(2,1),mp(2,-1),mp(-2,1),mp(-2,-1)};
void solve(){	
	map<pair<char,char>,bool> m;
	string s;
	cin>>s;
	for(int i='0';i<'9';++i){
		m[mp(s[0],i)]=true;
	}
	for(int i='a';i<='h';++i){
		m[mp(i,s[1])]=true;
	}
	do{
		m[mp(s[0],s[1])]=true;
		for(int i=0;i<8;++i){
			m[mp(s[0]+h[i].first,s[1]+h[i].second)]=true;
		}
	}
	while(cin>>s);
	int c=0;
	for(char i='1';i<='8';++i)
		for(char j='a';j<='h';++j)
			if(!m[mp(j,i)]){
				++c;
				//cout<<j<<i<<endl;
			}
		cout<<c;
}