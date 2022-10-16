#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxk=9;
const int Maxt=99;
typedef long long ll;
ll a[1<<Maxk|5][1<<Maxk|5];
int k,t;
struct Node{
	int x,y;
	Node(int _x=0,int _y=0){
		x=_x,y=_y;
	}
}pos[Maxt+5];
void mul_a(){
	static ll b[1<<Maxk|5][1<<Maxk|5];
	memset(b,0,sizeof b);
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<(1<<k);j++){
			for(int l=1;l<=t;l++){
				b[(i+pos[l].x)&((1<<k)-1)][(j+pos[l].y)&((1<<k)-1)]^=a[i][j];
			}
		}
	}
	memcpy(a,b,sizeof a);
}
void mul_2(){
	static Node nxt[Maxt+5];
	int len=0;
	for(int i=1;i<=t;i++){
		nxt[++len]=Node((pos[i].x<<1)&((1<<k)-1),(pos[i].y<<1)&((1<<k)-1));
	}
	std::sort(nxt+1,nxt+1+len,[](Node a,Node b){return a.x==b.x?a.y<b.y:a.x<b.x;});
	t=0;
	for(int i=1,j;i<=len;i=j+1){
		j=i;
		while(j<=len&&nxt[j].x==nxt[i].x&&nxt[j].y==nxt[i].y){
			j++;
		}
		j--;
		if((j-i+1)&1){
			pos[++t]=nxt[i];
		}
	}
}
int main(){
	scanf("%d",&k);
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<(1<<k);j++){
			scanf("%lld",&a[i][j]);
		}
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&pos[i].x,&pos[i].y);
		pos[i].x--,pos[i].y--;
	}
	for(int i=0;i<k;i++){
		mul_a();
		mul_2();
	}
	int ans=0;
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<(1<<k);j++){
			if(a[i][j]){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}