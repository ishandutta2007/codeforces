#include <bits/stdc++.h>
using namespace std;

int n;
string s1, s2;

int main(){
    int res = 0;
    scanf("%d", &n);
    getchar();
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < n; i++){
        if(s1[i] - s2[i] == 0) continue;
        if(i != n-1 && s1[i] - s2[i] + s1[i+1] - s2[i+1] == 0){
            s1[i] = s2[i] = s1[i+1] = s2[i+1] = '0';
            res++;
            continue;
        }
        s1[i] = s2[i];
        res++;
    }
    cout << res << endl;
}