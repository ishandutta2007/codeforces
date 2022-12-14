#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 60;

int T;
int N, M;
string str[MAX_N+1];

bool chk1(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(str[i][j]=='P')	return false;
		}
	}
	return true;
}

bool chk2(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(str[i][j]=='A')	return false;
		}
	}
	return true;
}

bool chk3(){
	bool tf = false;
	for(int i=0; i<M; i++){
		if(str[0][i]=='P'){
			break;
		}
		if(i==M-1){
			tf = true;
		}
	}
	for(int i=0; i<M; i++){
		if(str[N-1][i]=='P'){
			break;
		}
		if(i==M-1){
			tf = true;
		}
	}
	for(int i=0; i<N; i++){
		if(str[i][0]=='P'){
			break;
		}
		if(i==N-1){
			tf = true;
		}
	}for(int i=0; i<N; i++){
		if(str[i][M-1]=='P'){
			break;
		}
		if(i==N-1){
			tf = true;
		}
	}
	return tf;
}
bool chk4(){
	if(str[0][0]=='A' || str[0][M-1]=='A' || str[N-1][0]=='A' || str[N-1][M-1]=='A')	return true;
	bool chk = true;
	for(int i=0; i<N; i++){
		chk = true;
		for(int j=0; j<M; j++){
			if(str[i][j]=='P'){
				chk = false;
				break;
			}
		}
		if(chk)	return true;
	}
	for(int i=0; i<M; i++){
		chk = true;
		for(int j=0; j<N; j++){
			if(str[j][i]=='P'){
				chk = false;
				break;
			}
		}
		if(chk)	return true;
	}
	return false;
}
bool chk5(){
	for(int i=0; i<N; i++){
		if(str[i][0]=='A' || str[i][M-1]=='A')	return true;
	}
	for(int i=0; i<M; i++){
		if(str[0][i]=='A' || str[N-1][i]=='A')	return true;
	}
	return false;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++){
			cin>>str[i];
		}
		if(chk1()){
			printf("0\n");
			continue;
		}else if(chk2()){
			printf("MORTAL\n");
			continue;
		}
		else if(chk3()){
			printf("1\n");
			continue;
		}else if(chk4()){
			printf("2\n");
		}
		else if(chk5()){
			printf("3\n");
		}else{
			printf("4\n");
		}

	}
	return 0;
}