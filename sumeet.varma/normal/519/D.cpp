#include <bits/stdc++.h>

#define sl ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

long long val[26];
map<long long,int> a[26];

int main(){ sl

    for(int i=0;i<26;i++)
        cin >> val[i];

    //val[0] = 1;
    //val[1] = -1;

    string s;
    cin >> s;

    long long sum = 0;
    long long ans = 0;

    for(int i=0;i<s.length();i++){
        int ch = s[i]-(int)'a';
        long long cv = val[ch];
        sum += cv;
        if(a[ch].find(sum-cv) != a[ch].end())
            ans += a[ch][sum-cv];
        if(a[ch].find(sum) != a[ch].end())
            a[ch][sum]++;
        else
            a[ch].insert(make_pair(sum,1));
    }
/*
    int sum2[500050];
    for(int i=0;i<s.length();i++){
        sum2[i] = val[s[i]-(int)'a'];
        if(i != 0)
            sum2[i] += sum2[i-1];
    }

    long ans2 = 0;
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<s.length();j++){
            if(s[i] == s[j]){
                if(sum2[j-1] - sum2[i] == 0)
                    ans2++;
            }
        }
    }
*/
    cout << ans ;
    return 0 ;
}