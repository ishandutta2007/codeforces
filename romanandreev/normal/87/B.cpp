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
map<string,int> MP;
int calc(string s){
	int f1=0;
	int f2=0;
	string ss="";
	for (int i=0;i<(int)s.length();i++){
		if (s[i]=='*'){
			f1++;
		} else
		if (s[i]=='&'){
			f2++;
		} else
			ss+=s[i];
	}
	if (MP.find(ss)==MP.end()) return -1;
	if (MP[ss]==-1) return -1;
	return max(MP[ss]+f1-f2,-1);
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    string a,b,c;
	cin>>n;
	MP["void"]=0;
	MP["errtype"]=-1;
	for (int i=0;i<n;i++){
		cin>>a;
		if (a=="typedef"){
			cin>>b>>c;
			MP[c]=calc(b);
		} else {
			cin>>a;
			int ans=calc(a);
			if (ans==-1){	
				printf("errtype\n");
			} else {
				printf("void");
				for (int j=0;j<ans;j++){
					printf("*");
				}
				printf("\n");
			}
		}
	}	
    return 0;
}