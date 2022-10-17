#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll unsigned long long
ll s[Maxn+5];
struct Ques{
	ll l,r;
	int id;
	friend bool operator <(Ques p,Ques q){
		return p.r-p.l+1<q.r-q.l+1;
	}
}qu[Maxn+5];
struct Cha{
	int x,y;
	ll c;
	friend bool operator <(Cha p,Cha q){
		return p.c<q.c;
	}
}c[Maxn+5];
ll ans[Maxn+5];
int f_l[Maxn+5],f_r[Maxn+5];
int find_l(int x){
	if(f_l[x]==x){
		return x;
	}
	return f_l[x]=find_l(f_l[x]);
}
int find_r(int x){
	if(f_r[x]==x){
		return x;
	}
	return f_r[x]=find_r(f_r[x]);
}
void merge_l(int x,int y){
	int fa_x=find_l(x),fa_y=find_l(y);
	if(fa_x==fa_y){
		return;
	}
	f_l[fa_x]=fa_y;
}
void merge_r(int x,int y){
	int fa_x=find_r(x),fa_y=find_r(y);
	if(fa_x==fa_y){
		return;
	}
	f_r[fa_x]=fa_y;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	for(int i=1;i<n;i++){
		c[i].x=i;
		c[i].y=i+1;
		c[i].c=s[i+1]-s[i];
	}
	sort(c+1,c+n);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		cin>>qu[i].l>>qu[i].r;
		qu[i].id=i;
	}
	sort(qu+1,qu+1+q);
	ll sum=0,num=n;
	int now=1;
	for(int i=1;i<=q;i++){
		while(now<n&&c[now].c<qu[i].r-qu[i].l+1){
			num--;
			sum+=s[c[now].y]-s[c[now].x];
			now++;
		}
		ans[qu[i].id]=sum+num*(qu[i].r-qu[i].l+1);
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<" ";
	}
	puts("");
	return 0;
}