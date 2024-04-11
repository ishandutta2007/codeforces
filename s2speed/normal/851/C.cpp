#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1000;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

double gh(double a , double b){
	double h = a - b;
	if(h < 0){
		h = 0 - h;
	}
	return h;
}

bool zavie(double a[] , double b[]){
	ll h = 0 , d = 0;
	for(int j = 0 ; j < 5 ; j++){
		h += a[j] * b[j];
		d = sqrt(d * d + gh(a[j] , b[j]) * gh(a[j] , b[j]));
	}
	if(h / d > 0){
		return false;
	} else {
		return true;
	}
}

double cor[MAX_N][5] , a[3];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , x = 3 , o = 0;
	cin>>n;
	if(n <= 2){
		cout<<n<<"\n";
		for(int i = 1 ; i <= n ; i++){
			cout<<i<<" ";
		}
		cout<<"\n";
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 5 ; j++){
			cin>>cor[i][j];
		}
	}
	a[0] = 0; a[1] = 1; a[2] = 2;
	while(x <= n){
		int a0 = a[0] , a1 = a[1] , a2 = a[2];
		double b[3][2][5];
		for(int j = 0 ; j < 5 ; j++){
			b[0][0][j] = cor[a1][j] - cor[a0][j];
			b[0][1][j] = cor[a2][j] - cor[a0][j];
		}
		for(int j = 0 ; j < 5 ; j++){
			b[1][0][j] = cor[a0][j] - cor[a1][j];
			b[1][1][j] = cor[a2][j] - cor[a1][j];
		}
		for(int j = 0 ; j < 5 ; j++){
			b[2][0][j] = cor[a1][j] - cor[a2][j];
			b[2][1][j] = cor[a0][j] - cor[a2][j];
		}
		for(int j = 0 ; j < 3 ; j++){
			if(!zavie(b[j][0] , b[j][1])){
				a[j] = -1;
				if(x < n){
					a[j] = x;
				}
				x++;
			}
		}
	}
	for(int i = 0 ; i < 3 ; i++){
		if(a[i] != -1){
			o++;
		}
	}
	if(o == 2){
		for(int i = 0 ; i < 3 ; i++){
			if(i != a[0] && i != a[1] && i != a[2]){
				for(int j = 0 ; j < 3 ; j++){
					if(a[j] == -1){
						a[j] = i;
						break;
					}
				}
				break;
			}
		}
		int a0 = a[0] , a1 = a[1] , a2 = a[2];
		double b[3][2][5];
		for(int j = 0 ; j < 5 ; j++){
			b[0][0][j] = cor[a1][j] - cor[a0][j];
			b[0][1][j] = cor[a2][j] - cor[a0][j];
		}
		for(int j = 0 ; j < 5 ; j++){
			b[1][0][j] = cor[a0][j] - cor[a1][j];
			b[1][1][j] = cor[a2][j] - cor[a1][j];
		}
		for(int j = 0 ; j < 5 ; j++){
			b[2][0][j] = cor[a1][j] - cor[a2][j];
			b[2][1][j] = cor[a0][j] - cor[a2][j];
		}
		for(int j = 0 ; j < 3 ; j++){
			if(!zavie(b[j][0] , b[j][1])){
				a[j] = -1;
			}
		}
	}
	if(o == 0){
		cout<<"0\n";
		return 0;
	}
	for(int i = 0 ; i < 3 ; i++){
		if(a[i] != -1){
			a[0] = a[i];
			break;
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(i == a[0]){
			continue;
		}
		for(int j = i + 1 ; j < n ; j++){
			if(j == a[0]){
				continue;
			}
			a[1] = i;
			a[2] = j;
			int a0 = a[0] , a1 = a[1] , a2 = a[2];
			double b[3][2][5];
			for(int j = 0 ; j < 5 ; j++){
				b[0][0][j] = cor[a1][j] - cor[a0][j];
				b[0][1][j] = cor[a2][j] - cor[a0][j];
			}
			for(int j = 0 ; j < 5 ; j++){
				b[1][0][j] = cor[a0][j] - cor[a1][j];
				b[1][1][j] = cor[a2][j] - cor[a1][j];
			}
			for(int j = 0 ; j < 5 ; j++){
				b[2][0][j] = cor[a1][j] - cor[a2][j];
				b[2][1][j] = cor[a0][j] - cor[a2][j];
			}
			for(int j = 0 ; j < 3 ; j++){
				if(!zavie(b[j][0] , b[j][1])){
					a[j] = -1;
				}
			}
			if(a[0] == -1){
				cout<<"0\n";
				return 0;
			}
		}
	}
	cout<<"1\n"<<a[0] + 1<<"\n";
	return 0;
}