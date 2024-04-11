#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
int n;
string t;
string c;
string s[1000];
int ff[1000];
char lower(char a){
	if (a>='A' && a<='Z') return a-'A'+'a';
	return a;
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	cin>>t;
	cin>>c;
	c[0]=lower(c[0]);
	for (int j=0;j<n;j++)
		for (int i=0;i<(int)t.length()-(int)s[j].length()+1;i++){
			bool gd=true;
			for (int k=0;k<(int)s[j].length();k++){
				if (lower(s[j][k])!=lower(t[i+k])){
					gd=false;
					break;
				}
			}
			if (gd){
				for (int k=0;k<(int)s[j].length();k++){
					ff[i+k]=1;
				}
			}
		}
	for (int i=0;i<(int)t.length();i++){
		if (ff[i]){
			if (lower(t[i])==lower(c[0])){
				if (lower(t[i])=='a'){
					if (t[i]>='A' && t[i]<='Z')
						cout<<'B';
					else
						cout<<'b';
				} else {
					if (t[i]>='A' && t[i]<='Z')
						cout<<'A';
					else
						cout<<'a';
				}
			} else { 
				if (t[i]>='A' && t[i]<='Z')
					cout<<(char)(c[0]-'a'+'A');
				else
					cout<<c;
			}
		} else
			cout<<t[i];
	}
	cout<<endl;
    return 0;
}