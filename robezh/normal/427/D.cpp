#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int INF = 10005;

string s1,s2;
int len1, len2;
int lcp1[N][N], lcp2[N][N], lcp3[N][N];
int l1[N], l2[N], l3[N];

void getlcp(int lcp[][N], string s1, string s2){
    int len1 = s1.length(), len2 = s2.length();
    for(int i = len1 - 1; i >= 0; i--){
        for(int j = len2 - 1; j >= 0; j--){
            if(s1[i] != s2[j]){lcp[i][j] = 0;}
            else if(i == len1 - 1 || j == len2 - 1){
                lcp[i][j] = 1;
            }
            else lcp[i][j] = lcp[i+1][j+1] + 1;
        }
    }
}

int main(){
    cin >> s1 >> s2;
    len1 = s1.length(), len2 = s2.length();
    getlcp(lcp1, s1, s2);
    getlcp(lcp2, s1, s1);
    getlcp(lcp3, s2, s2);
    for(int i = 0; i < len1; i++) for(int j = 0; j < len1; j++) if(i != j) l2[i] = max(l2[i], lcp2[i][j]);
    for(int i = 0; i < len2; i++) for(int j = 0; j < len2; j++) if(i != j) l3[i] = max(l3[i], lcp3[i][j]);
    int res = INF;
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(lcp1[i][j] > l2[i] && lcp1[i][j] > l3[j]){
                res = min(res, max(l2[i], l3[j]) + 1);
            }
        }
    }
    cout << (res == INF ? -1 : res);
}