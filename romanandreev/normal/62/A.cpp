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
bool can(int d,int m){
	return (m>=d-1 && m<=2*(d+1));
}
int main(){
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	bool ans=can(a,d)||can(b,c);
	if (ans) cout<<"YES"<<endl;else 
			 cout<<"NO"<<endl;
    return 0;
}