#include <bits/stdc++.h>

using namespace std;

const int kN = 2e3 + 7;
const int kInf = 1e9;
const string digits[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int number_digits[10];

int numbers[kN];
int cost[1 << 7][10];
pair<bool, bool> dp[kN][kN];
int n, k;

bool solve(int pos, int k_left, string &return_number){
    if(pos == n)
        return k_left == 0;
    if(k_left < 0)
        return false;

    auto &[answer, solved] = dp[pos][k_left];
    if(solved)
        return answer;

    solved = true;
    answer = false;

    for(int i = 9; i >= 0; --i){
        if(cost[numbers[pos]][i] == kInf)
            continue;

        if(solve(pos + 1, k_left - cost[numbers[pos]][i], return_number)){
            return_number += (char)('0' + i);
            return answer = true;
        }
    }

    return answer;
}  

int from_binary_to_int(string s){
    int answer = 0;
    for(int i = 0; i < 7; ++i){
        answer *= 2;
        answer += (s[i] - '0');
    }

    return answer;
}

void preprocess(){
    for(int i = 0; i < 10; ++i)
        number_digits[i] = from_binary_to_int(digits[i]);

    for(int x = 0; x < (1 << 7); ++x){
        for(int digit = 0; digit < 10; ++digit){
            int y = number_digits[digit];

            if((x | y) != y){
                cost[x][digit] = kInf;
                continue;
            }

            int t = (x ^ y);
            cost[x][digit] = 0;

            for(int bit = 0; bit < 7; ++bit)
                if(t & (1 << bit))
                    ++cost[x][digit];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        string binary;
        cin >> binary;

        numbers[i] = from_binary_to_int(binary);
    }

    preprocess();

    string answer = "";
    bool solved = solve(0, k, answer);

    if(!solved){
        cout << "-1\n";
        return 0;
    }
    else{
        reverse(answer.begin(), answer.end());
        cout << answer << "\n";
    }
}