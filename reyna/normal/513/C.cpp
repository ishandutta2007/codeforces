//In the name of God
#include <iostream>
#include <iomanip>
using namespace std;
long double L[5],R[5];
int main(){
	int n;
	cin >> n;
	long double ans = 0;
	long double cte = 1;
	for(int i = 0; i < n;i++)
		cin >> L[i] >> R[i],cte *= (R[i]-L[i]+1);
	for(int num = 1; num <= 10000;num++){
		for(int k = 1; k < (1 << n);k++){
			long double now = 1;
			int cnt = 0;
			for(int i = 0; i < n;i++)
				if(k & (1 << i))
					cnt++;
			if(cnt < 2){
				continue;
			}
			for(int i = 0; i < n;i++){
				if((k & (1 << i))){
					if(L[i] <= num && num <= R[i]){
						now *= (long double)1 / (R[i] - L[i] + 1);
					}else{
						now = 0;
						break;
					}
				}else{
					now *= (max((long double)0,min(R[i],(long double)num-1)-L[i]+1))/(R[i]-L[i]+1);
				}
			}
			ans += now * num;
		}
	}
	for(int num = 1; num <= 10000;num++){
		for(int j = 0; j < n;j++){
			if(num < R[j]){
				for(int r = 1; r < (1 << n);r++){
					if((1 << j) & r)
						continue;
					long double now = ((R[j] - max((long double)num+1,L[j])+1)/(R[j]-L[j]+1));
					for(int k = 0; k < n;k++){
						if(k == j)
							continue;
						if(!((1 << k) & r)){
							if(num-1 < L[k]){
								now = 0;
								break;
							}
							now *= (max((long double)0,min((long double)num-1,R[k])-L[k]+1))/(R[k]-L[k]+1);
						}else{
							if(L[k] <= num && num <= R[k]){
								now *= ((long double)1)/(R[k]-L[k]+1);
							}else{
								now = 0;
								break;
							}
						}
					}
					if(now)
					ans += now * num;
				}
			}
		}
	}
	cout << setprecision(10) << fixed << ans << endl;
	return 0;
}