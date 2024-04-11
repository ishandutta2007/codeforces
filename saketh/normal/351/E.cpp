#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

int N;
vector<int> num;

int main(){
    setup();
    
    cin >> N;
    num.resize(N);
    
    for(int i=0; i<N; i++){
        cin >> num[i];
        num[i] = abs(num[i]);
    }

    int ans = 0;

    while(num.size()){
        int big = 0;
        for(int v : num) big = max(big, v);
        
        int cnt = 0;
        for(int v : num) cnt += v == big;

        int seen = 0;
        for(int i=0; i<num.size(); i++){
            if(num[i] != big) continue;
            int left = i - seen;   
            int right = num.size() - i - cnt + seen;
            ans += min(left, right);
            seen++;
        }

        vector<int> tmp;
        for(int v : num)
            if(v != big)
                tmp.push_back(v);
        swap(num, tmp);
    }

    cout << ans << endl;
}