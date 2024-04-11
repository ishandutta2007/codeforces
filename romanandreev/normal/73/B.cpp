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
int a[1000000];
int b[1000000];
int p[1000000];
char s[1000000][22];
int n,m,pos,vc,pl;
char nm[22];
char tmp[22];

bool cmp(int x,int y){
	return (a[x]<a[y] || (a[x]==a[y] && strcmp(s[x],s[y])>0));
}                                   
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++){
    	scanf("%s%d",s[i],&a[i]);
    	p[i]=i;
    }
    scanf("%d",&m);
    for (int i=0;i<m;i++){
    	scanf("%d",&b[i]);
    }
    sort(b,b+n);
    scanf("%s",nm);
    pos=0;
    for (int i=0;i<n;i++){
    	if (strcmp(s[i],nm)==0){
    		pos=i;
    	}
    }
    swap(a[0],a[pos]);
    memcpy(tmp,s[0],sizeof(s[0]));
    memcpy(s[0],s[pos],sizeof(s[0]));
    memcpy(s[pos],tmp,sizeof(s[0]));
    sort(p+1,p+n,cmp);
    vc=a[0]+b[n-1];
    pl=n;
    int yk=n-2;
    int i;
    for (int j=1;j<n;j++){
    	i=p[j];
    	while (yk>=0 && (a[i]+b[yk]>vc || (a[i]+b[yk]==vc && strcmp(s[0],s[i])>0)))
    		yk--;
    	if (yk==-1) break;
    	pl--;
    	yk--;
    }
    cout<<pl<<" ";
    vc=a[0]+b[0];
    pl=1;
    yk=1;
    for (int j=n-1;j>=1;j--){
    	i=p[j];
    	while (yk<n && (a[i]+b[yk]<vc || (a[i]+b[yk]==vc && strcmp(s[0],s[i])<0)))
    		yk++;
    	if (yk==n) break;
    	pl++;
    	yk++;
    }
    cout<<pl<<endl;
    return 0;
}