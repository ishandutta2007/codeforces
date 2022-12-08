#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=100005,B=700;
struct node{
	int l,r,num;	
}p[N];
int n,m,a[N],s[N],si[N],tot,ans[N],cnt[N],tmp[N];

inline bool cmp(node a,node b){
	if(a.l/B!=b.l/B) return a.l/B<b.l/B;
	return a.r<b.r;
}
priority_queue<int,vector<int>,greater<int> > q;
inline int solve(){
	int ans=0;
	for(int i=1;i<=B;i++) tmp[i]=cnt[i];
	int pt=0;
	for(int i=1;i<=B/2;i++){
		if(tmp[i]>=2){
			ans+=tmp[i]/2*i*2;
			tmp[i<<1]+=tmp[i]>>1;
			tmp[i]&=1;
		}
		if(tmp[i]){
			pt=max(pt,i+1);
			while(pt<=B/2&&!tmp[pt]) pt++;
			if(pt>B/2) q.push(i);
			else{
				ans+=pt+i;tmp[i]--;tmp[pt]--;
				tmp[pt+i]++;	
			}
		}
	}
	for(int i=B/2+1;i<=B;i++)
		for(int j=1;j<=tmp[i];j++) q.push(i);
	for(int i=1;i<=tot;i++)
		if(si[s[i]]>B) q.push(si[s[i]]);
	while(!q.empty()){
		int x=q.top(),y;q.pop();
		if(q.empty()) break;
		y=q.top();q.pop();
		q.push(x+y);ans+=x+y;
	}
	return ans;
}
inline void ins(int x){
	cnt[si[a[x]]]--;
	si[a[x]]++;
	cnt[si[a[x]]]++;
}
inline void del(int x){
	cnt[si[a[x]]]--;
	si[a[x]]--;	
	cnt[si[a[x]]]++;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),si[a[i]]++;
	for(int i=1;i<=100000;i++) if(si[i]>B) s[++tot]=i;
	for(int i=1;i<=100000;i++) cnt[si[i]]++;
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&p[i].l,&p[i].r),p[i].num=i;
	sort(p+1,p+m+1,cmp);
	int l=1,r=n;
	for(int i=1;i<=m;i++){
		while(l>p[i].l) l--,ins(l);
		while(r<p[i].r) r++,ins(r);
		while(l<p[i].l) del(l),l++;	
		while(r>p[i].r) del(r),r--;
//		printf("%d\n",p[i].num);
		if(i==1||p[i].l!=p[i-1].l||p[i].r!=p[i-1].r) ans[p[i].num]=solve(); else ans[p[i].num]=ans[p[i-1].num];
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}