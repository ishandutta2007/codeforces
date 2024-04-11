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
typedef vector<int> vi;
char s[1000000];
char t[1000000];
vi v[300];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for (int i=0;i<k;i++){
		v[s[i]].pb(i);
	}
	ll ans;
	int m,mn;
	for (int i=0;i<n;i++){
		scanf("%s",t);
		m=strlen(t);
		ans=0;
		for (int j=0;j<m;j++){
			if (v[t[j]].size()==0) ans+=m; else {
				k=lower_bound(v[t[j]].begin(),v[t[j]].end(),j)-v[t[j]].begin();
				mn=abs(v[t[j]][0]-j);
				for (int p=max(k-2,0);p<min(k+3,(int)v[t[j]].size());p++)
					mn=min(mn,abs(j-v[t[j]][p]));
				ans+=mn;
			}
		}
		printf("%I64d\n",ans);
	}
    return 0;
}