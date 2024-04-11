#include<iostream>

using namespace std;

int main(){
	int t , a , b , c , min , mid , max; 
	long long counter;
	cin>>t;
	while(t > 0){
		cin>>a>>b>>c;
		counter = 0;
		if(a < b){
			if(b <= c){
				min = a;
				mid = b;
				max = c;
			}
			else{
				max = b;
				if(a < c){
					min = a;
					mid = c;
				}
				else{
					min = c;
					mid = a;
				}
			}
		}
		else{
			if(a <= c){
				min = b;
				mid = a;
				max = c;
			}
			else{
				max = a;
				if(a < c){
					min = b;
					mid = c;
				}
				else{
					min = c;
					mid = b;
				}
			}
		}
		counter += min;
		max -= min;
		if(max - mid < 0){
			counter += max + (mid - max) / 2;
		}
		else{
			counter += mid;
		}
		cout<<counter<<endl;
		t--;
	}
	return 0;
}