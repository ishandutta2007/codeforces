#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , m;
	cin>>n>>m;
	ll x = 1 , y = 1 , dx = 0 , dy = 0 , ln = n , lm = m;
	for( ; ; ){
		if(ln == 1){
			y = 1;
			while(lm != 0){
				cout<<x<<" "<<y<<"\n";
				if(lm > 0){
					lm--;
				} else {
					lm++;
				}
				y += lm;
				lm = 0 - lm;
			}
			return 0;
		}
		if(lm == 1){
			while(ln != 0){
				cout<<x<<" "<<y<<"\n";
				if(ln > 0){
					ln--;
				} else {
					ln++;
				}
				x += ln;
				ln = 0 - ln;
			}
			return 0;
		}
		while(ln > 1){
			dx = ln - 1;
			dy = lm - 1;
			for(int i = 0 ; i < lm * 2 ; i++){
				cout<<x<<" "<<y<<"\n";
				if(i % 2 == 0){
					x += dx;
					y += dy;
				} else {
					x -= dx;
					y -= dy;
				}
				dy--;
			}
			ln -= 2;
			x = (n - ln) / 2 + 1;
			y = 1;
		}
		if(ln == 0){
			return 0;
		}
	}
	return 0;
}