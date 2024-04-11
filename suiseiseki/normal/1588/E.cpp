#include <cmath>
#include <cstdio>
#include <complex>
#include <algorithm>
#define double long double
#define acos acosl
#define atan2 atan2l
#define asin asinl
#define sqrt sqrtl
#define x real
#define y imag
typedef long long ll;
const double PI=atan2(0,-1);
const int Maxn=3000;
const double eps=1e-9;
int n,R;
bool cir[Maxn+5][Maxn+5];
ll dis[Maxn+5];
bool able[Maxn+5];
bool ans[Maxn+5][Maxn+5];
double arc[Maxn+5];
std::complex<ll> a[Maxn+5];
ll dot(std::complex<ll> a,std::complex<ll> b){
	return (std::conj(a)*b).x();
}
ll cross(std::complex<ll> a,std::complex<ll> b){
	return (std::conj(a)*b).y();
}
double angle(std::complex<ll> a){
	return atan2(a.y(),a.x());
}
int main(){
	scanf("%d%d",&n,&R);
	for(int i=1;i<=n;i++){
		int tmp_x,tmp_y;
		scanf("%d%d",&tmp_x,&tmp_y);
		a[i]={tmp_x,tmp_y};
	}
	for(int i=1;i<=n;i++){
		double all_start=0,all_len=2*PI;
		for(int j=1;j<=n;j++){
			if(dot(a[j]-a[i],a[j]-a[i])<=1ll*R*R){
				continue;
			}
			double dis=sqrt(dot(a[j]-a[i],a[j]-a[i]));
			double ang=angle(a[j]-a[i]);
			double theta=asin(R/dis);
			double cur_left=ang-theta-all_start,cur_right=ang+theta-all_start;
			if(all_len==2*PI){
				all_start=cur_left;
				if(all_start<0){
					all_start+=2*PI;
				}
				all_len=cur_right-cur_left;
				continue;
			}
			if(cur_right<0){
				cur_left+=2*PI,cur_right+=2*PI;
			}
			if(cur_left>all_len){
				cur_left-=2*PI,cur_right-=2*PI;
			}
			cur_left=std::max(0.0l,cur_left),cur_right=std::min(cur_right,all_len);
			if(cur_left>cur_right){
				all_len=-1;
				break;
			}
			all_len=cur_right-cur_left;
			all_start+=cur_left;
			if(all_start>=2*PI){
				all_start-=2*PI;
			}
		}
		if(all_len<0){
			continue;
		}
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			double ang=angle(a[j]-a[i])-all_start;
			if(ang<0){
				ang+=2*PI;
			}
			if(0<=ang&&ang<=all_len){
				ans[i][j]=1;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ans[i][j]&&ans[j][i]){
				sum++;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}