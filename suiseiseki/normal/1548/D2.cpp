#include <cstdio>
#include <algorithm>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
typedef long long ll;
const int Maxn=6000;
struct Node{
	int x,y;
}a[Maxn+5];
int f[Maxn+5][4][4][4];
int n;
ll ans[2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int tmp=gcd(std::abs(a[i].x-a[j].x),std::abs(a[i].y-a[j].y))%4;
			f[j][tmp][a[i].x%4][a[i].y%4]++;
			f[i][tmp][a[j].x%4][a[j].y%4]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int p=0;p<4;p++){
			for(int q=0;q<4;q++){
				for(int x_a=0;x_a<4;x_a++){
					for(int y_a=0;y_a<4;y_a++){
						for(int x_b=0;x_b<4;x_b++){
							for(int y_b=0;y_b<4;y_b++){
								int tmp=gcd(std::abs(x_a-x_b),std::abs(y_a-y_b));
								if(tmp&1){
									continue;
								}
								tmp=(tmp+p+q)>>1;
								int s=x_a*y_b-x_b*y_a+x_b*a[i].y-a[i].x*y_b+a[i].x*y_a-x_a*a[i].y;
								if(!(((s>>1)^tmp)&1)){
									ans[p&1]+=1ll*f[i][p][x_a][y_a]*(f[i][q][x_b][y_b]-(p==q&&x_a==x_b&&y_a==y_b));
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n",ans[0]/6+ans[1]/2);
	return 0;
}