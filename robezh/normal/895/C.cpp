#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int num[100005];
int dp[2][540000];
int C[80][80];
int po[100005];


int cnt[71];

int prime[19]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int code[71]= {0,0,262144,131072,0,65536,393216,32768,262144,0,327680,16384,
               131072,8192,294912,196608,0,4096,262144,2048,65536,163840,278528,1024,393216,0,270336,131072,32768,512,458752,
               256,262144,147456,266240,98304,0,128,264192,139264,327680,64,425984,32,16384,65536,263168,16,131072,0,262144,
               135168,8192,8,393216,81920,294912,133120,262656,4,196608,2,262400,32768,0,73728,409600,1,4096,132096,360448
              };

int main() {
    //for(int i = 0; i < 2; i++) fill(dp[i], dp[i]+524288, 0);
    dp[0][0] = 1;
    for(int i = 0; i < 80; i++) C[0][i] = 1;
    for(int i = 0; i < 80; i++) C[i][i] = 1;
    //for(int i = 0; i < 80; i++) C[i][i] = 1;
    for(int i = 1; i < 80; i++) {
        for(int j = 1; j < 80; j++) {
            C[i][j] = (C[i][j-1] + C[i-1][j-1]) % mod;
        }
    }
    po[0] = 1;
    for(int i = 1; i < 100005; i++){
    	po[i] = (po[i-1] * 2) % mod;
	}


    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]), cnt[num[i]]++;

    for(int i = 1; i <= 70; i++) {
    	int odd = 0, even = 0;
    	if(cnt[i] != 0){
    		odd = po[cnt[i] - 1];
    		even = po[cnt[i]-1];
		}
		else{
			odd = 0;
			even = 1;
		}
		
		//cout << odd << " " << even << endl;
		
        for(int j = 0; j < 524288; j++) {
            dp[i&1][j] = (((ll)dp[!(i&1)][j] * even) % mod + ((ll)dp[!(i&1)][j^code[i]] * odd) % mod) % mod ;
        }
    }
    cout << dp[70&1][0] - 1;
}