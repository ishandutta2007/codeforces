//In the name of God
#include <iostream>
using namespace std;
long long f[15];
int mins[4];
int pri[4];
int cnt[11][4];
int init(){
        cnt[9][3]++;
        cnt[9][2]++;
        cnt[9][1]+=4;
        cnt[9][0]+=7;
        cnt[8][3]++;
        cnt[8][2]++;
        cnt[8][1]+=2;
        cnt[8][0]+=7;
        cnt[7][3]++;
        cnt[7][2]++;
        cnt[7][1]+=2;
        cnt[7][0]+=4;
        cnt[6][2]++;
        cnt[6][1]+=2;
        cnt[6][0]+=4;
        cnt[5][2]++;
        cnt[5][1]+=1;
        cnt[5][0]+=3;
        cnt[4][1]+=1;
        cnt[4][0]+=3;
        cnt[3][1]+=1;
        cnt[3][0]+=1;
        cnt[2][0]++;
}
int main(){
    init();
    int n;
    cin >> n;
    pri[0] = 2;
    pri[1] = 3;
    pri[2] = 5;
    pri[3] = 7;
    f[0] = 1;
    for(int i = 1; i < 10;i++)
        f[i] = f[i-1] * i;
    string S;
    cin >> S;
    string ans = "";
    long long num = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0; j < 4;j++)
            mins[j] += cnt[S[i]-'0'][j];
    }
    for(int i = 3;i >= 0;--i){
        int tmp = mins[i];
        for(int j = 0; j < tmp;j++){
            cout << pri[i];
            for(int k = 0;k < 4;k++){
                mins[k]-=cnt[pri[i]][k];
            }
        }
    }
    return 0;
}