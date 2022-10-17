#include <iostream>
using namespace std;

string s;
int K, v[26];
int val[1005];
int sum[1005];

int main(){
    cin >> s >> K;

    int b = 0;
    for(int i=0; i<26; i++){
        cin >> v[i];
        if(v[i] > v[b]) b = i;
    }

    sum[0] = v[s[0] - 'a'];
    val[0] = v[s[0] - 'a'];
    for(int i=1; i<s.size(); i++){
        sum[i] = sum[i-1] + v[s[i] - 'a'];
        val[i] = val[i-1] + (i+1) * v[s[i] - 'a'];
    }

    int ans = 0;
    for(int i=0; i<=s.size(); i++){
        int cand = val[s.size()-1];
        cand += K * (sum[s.size()-1] - (i?sum[i-1]:0));
    
        for(int j=0; j<K; j++)
            cand += (i+j+1) * v[b];
        ans = max(ans, cand);
    }

    cout << ans << endl;
}