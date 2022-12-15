#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        long long a, b, n;
        cin >> a >> b >> n;

        if(a < b)
            swap(a, b);

        long long ans_even = 0, ans_odd = 0;
        long long new_a, new_b;

        new_a = a;
        new_b = b;
        while(new_a <= n){
            new_b += new_a;
            new_a += new_b;
            ans_even += 2;
        }

        new_a = a;
        new_b = b;
        while(new_a <= n){
            if(ans_odd >= ans_even - 2){
                new_a += new_b;
                if(new_a <= n){
                    ans_odd += 3;
                    break;
                }
                else{
                    ans_odd++;
                    break;
                }
            }
            new_b += new_a;
            new_a += new_b;
            ans_odd += 2;
        }

        cout << min(ans_even, ans_odd) << "\n";
    }
}