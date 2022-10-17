#include<iostream>
#include<string>
#include<set>
using namespace std;

string S;
set<int> a[26];
int dp[100005][105];
bool us[100005][105];

int thresh(int end, int len, char c){
    int cap = dp[end-1][len-2];
    set<int>::iterator it = a[c-'a'].lower_bound(cap);
    if(it == a[c-'a'].begin()) return -1;
    it--;
    return *it;
}

void print(int n, int l){
    if(l==1)
        cout << S[n];
    if(l<=1) return;
    if(us[n][l]){
        cout << S[n];
        print(n-1, l-2);
        cout << S[n];
    }
    else print(n-1, l);
}

int main(){
    cin >> S;
    for(int c=0; c<S.length(); c++)
        a[S[c]-'a'].insert(c);
    
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int l=2; l<=100; l++)
        dp[0][l] = -1;

    for(int n=1; n<S.length(); n++){
        dp[n][0] = n+1;
        dp[n][1] = n;
        for(int l=2; l<=100; l++){
            dp[n][l] = dp[n-1][l];
            int t = thresh(n, l, S[n]);
            if(t == -1) continue;
            if(t > dp[n][l]){
                dp[n][l] = t;
                us[n][l] = true;
            }
        }
    }
    
    for(int l=100; l>0; l--)
        if(dp[S.length()-1][l] != -1){
            print(S.length()-1, l);
            cout << endl;
            break;
        }

    return 0;
}