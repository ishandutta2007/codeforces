#include <bits/stdc++.h>

using namespace std;

const long long k_Max = 2e16;
const int k_N = (1 << 6);

long long x0, y0, ax, ay, bx, by;
long long xs, ys, t;

long long x[k_N], y[k_N];
int n;

void build_x_y(){
    x[0] = x0;
    y[0] = y0;

    for(n = 1; x[n - 1] <= k_Max && y[n - 1] <= k_Max; ++n){
        x[n] = x[n - 1] * ax + bx;
        y[n] = y[n - 1] * ay + by;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;

    build_x_y();

    int answer = 0;
    for(int i = 0; i < n; ++i){
        long long curr_t = abs(x[i] - xs) + abs(y[i] - ys);
        if(curr_t <= t)
            answer = max(1, answer);

        for(int j = i - 1; j >= 0; --j){
            curr_t += abs(x[j] - x[j + 1]) + abs(y[j] - y[j + 1]);
            if(curr_t > t)
                break;
            answer = max(i - j + 1, answer);

            long long curr_t_2 = 2 * curr_t;
            for(int k = i + 1; k < n; ++k){
                curr_t_2 += abs(x[k] - x[k - 1]) + abs(y[k] - y[k - 1]);
                if(curr_t_2 > t)
                    break;
                answer = max(k - j + 1, answer);
            }
        }

        curr_t = abs(x[i] - xs) + abs(y[i] - ys);

        for(int j = i + 1; j < n; ++j){
            curr_t += abs(x[j] - x[j - 1]) + abs(y[j] - y[j - 1]);
            if(curr_t > t)
                break;
            answer = max(j - i + 1, answer);

            long long curr_t_2 = 2 * curr_t;
            for(int k = i - 1; k >= 0; --k){
                curr_t_2 += abs(x[k] - x[k + 1]) + abs(y[k] - y[k + 1]);
                if(curr_t_2 > t)
                    break;
                answer = max(j - k + 1, answer);
            }
        }
    }

    cout << answer << "\n";
}