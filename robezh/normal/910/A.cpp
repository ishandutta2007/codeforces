#include <bits/stdc++.h>
using namespace std;

int n,d;
string str;

int main(){
    scanf("%d%d", &n, &d);
    getchar();
    getline(cin, str);
    int i = 0;
    int cnt = 0;
    while(true){
        if(i + d >= n-1){
            cnt ++;
            break;
        }
        int ori = i;
        i += d;
        while(str[i] == '0') i--;
        if(i == ori){
            cnt = -1;
            break;
        }
        cnt ++;
    }
    cout << cnt;
}