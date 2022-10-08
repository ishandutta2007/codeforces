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

int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,p,m,a,b,c,d,e;
	cin>>n;
	int mx=-((int)1e9);
	string ms="=(";
	string s;
    for (int i=0;i<n;i++){
    	cin>>s>>p>>m>>a>>b>>c>>d>>e;
    	if (a+b+c+d+e+100*p-50*m>mx){
    		mx=a+b+c+d+e+100*p-50*m;
    		ms=s;
    	}
    }
    cout<<ms<<endl;
    return 0;
}