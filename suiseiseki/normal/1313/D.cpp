#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
int count_bit(int x){
	int ans=0;
	while(x){
		x-=(x&(-x));
		ans++;
	}
	return ans;
}
const int Maxn=100000;
const int Maxk=8;
int n,m,k;
struct Segment{
	int l,r;
}seg[Maxn+5];
struct Node{
	int pos,val,id;
	friend bool operator <(Node p,Node q){
		if(p.pos==q.pos){
			return p.val<q.val;
		}
		return p.pos<q.pos;
	}
}a[Maxn<<1|5];
int len;
int id[Maxk+5];
int f[2][1<<Maxk|5];
bool check(int x){
	for(int i=0;i<k;i++){
		if(((x>>i)&1)&&id[i]==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++){
		read(seg[i].l),read(seg[i].r);
		a[++len].pos=seg[i].l;
		a[len].val=1;
		a[len].id=i;
		a[++len].pos=seg[i].r+1;
		a[len].val=-1;
		a[len].id=i;
	}
	sort(a+1,a+1+len);
	int last_pos=a[1].pos;
	int pos_id;
	for(int i=1;i<=len;i++){
		memset(f[1],0,sizeof f[1]);
		if(a[i].val==-1){
			for(pos_id=0;id[pos_id]!=a[i].id;pos_id++);
			id[pos_id]=0;
			for(int j=0;j<(1<<k);j++){
				if(!check(j)){
					continue;
				}
				f[1][j]=max(f[0][j]+(count_bit(j)&1)*(a[i].pos-last_pos),f[0][j|(1<<pos_id)]+((count_bit(j|(1<<pos_id))&1)*(a[i].pos-last_pos)));
			}
		}
		else{
			for(pos_id=0;id[pos_id]>0;pos_id++);
			for(int j=0;j<(1<<k);j++){
				if(!check(j)){
					continue;
				}
				f[1][j]=f[0][j]+(count_bit(j)&1)*(a[i].pos-last_pos);
				f[1][j|(1<<pos_id)]=f[0][j]+(count_bit(j)&1)*(a[i].pos-last_pos);
			}
			id[pos_id]=a[i].id;
		}
		last_pos=a[i].pos;
		swap(f[0],f[1]);
	}
	printf("%d\n",f[0][0]);
	return 0;
}