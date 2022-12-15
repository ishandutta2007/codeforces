#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s;
    cin >> m >> s;

    if(s == 0){
        if(m == 1)
            cout << "0 0\n";
        else
            cout << "-1 -1\n";
        return 0;
    }

    string answer1 = "", answer2 = "";

    int curr = s;
    for(int i = 0; i < m; ++i){
        int x;
        if(i == m - 1)
            x = curr;
        else
            x = min(curr - 1, 9);

        if(x < 0 || x > 9){
            cout << "-1 -1\n";
            return 0;
        }

        answer1 += (x + '0');
        curr -= x;
    }

    reverse(answer1.begin(), answer1.end());
    cout << answer1 << " ";

    curr = s;
    for(int i = 0; i < m; ++i){
        int x = min(curr, 9);

        answer2 += (x + '0');
        curr -= x;
    }

    cout << answer2 << "\n";
    return 0;
}