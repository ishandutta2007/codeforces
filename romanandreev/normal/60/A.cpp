#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
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
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n,m,lf,rg,k;
    string s1,s2,s3,s4;
	cin>>n>>m;
	lf=1;
	rg=n;
	for (int i=0;i<m;i++){
		cin>>s1>>s2>>s3>>s4>>k;
		if (s3=="right") lf=max(lf,k+1);
				else rg=min(rg,k-1);

	}
	if (lf<=rg) cout<<rg-lf+1<<endl; else
		cout<<-1<<endl;
    return 0;
}