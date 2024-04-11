#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<limits>
using namespace std;

typedef long long ll;

string str = "What are you doing at the end of the world\? Are you busy\? Will you save us\?";
string str1 = "What are you doing while sending \"";
string str2 = "\"\? Are you busy\? Will you send \"";
string str3 = "\"\?";

ll INF = numeric_limits<ll>::max();
ll a[100005][6];
ll pre[100005][6];
int n;
ll k;
ll maxv = str.length();

int main() {
	//cout << str3[0] << str3[1] << str3[2];
    int q;
    scanf("%d", &q);
    while(q--) {
        maxv = str.length();
        bool flag = false;
        cin >> n >> k;
        k--;
        pre[0][4] = str.length();
        for(int i = 1; i <= n; i++) {
            a[i][0] = 34;
            a[i][1] = pre[i-1][4];
            a[i][2] = 32;
            a[i][3] = pre[i-1][4];
            a[i][4] = 2;
            pre[i][0] = 34;
            for(int j = 1; j <= 4; j++) {
            	if(pre[i][j-1] > k){
            		pre[i][j] = pre[i][j-1] + 1;
				}else{
                pre[i][j] = pre[i][j-1] + a[i][j];
                }
            }
            maxv = max(maxv, pre[i][4]);
        }
        if(k >= maxv) {
            cout << '.';
            continue;
        }
//		for(int i = 1; i <= n; i++){
//			for(int j = 0; j <= 4; j++){
//				cout <<
//			}
//		}
        int i = n;
        while(i > 0) {
            int ind = upper_bound(pre[i], pre[i]+5, k) - pre[i];
            if(ind != 0) {
                k -= pre[i][ind-1];
            }
            if(ind == 0) {
                cout << str1[k];
                break;
            } else if(ind == 2) {
                cout << str2[k];
                break;
            } else if(ind == 4) {
                cout << str3[k];
                break;
            }
            i--;
        }
        if(i == 0) {
            cout << str[k];
        }
    }
}