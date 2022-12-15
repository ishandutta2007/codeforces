#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert){
    int n = a.size();

    for(int i = 1, j = 0; i < n; ++i){
        int bit = n >> 1;
        for(; bit & j; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if(i < j)
            swap(a[i], a[j]);
    }

    for(int len = 2; len <= n; len <<= 1){
        double angle = 2.0 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(angle), sin(angle));
        for(int i = 0; i < n; i += len){
            cd w(1);
            for(int j = 0; j < (len >> 1); ++j){
                cd u = a[i + j], v = a[i + j + (len >> 1)] * w;
                a[i + j] = u + v;
                a[i + j + (len >> 1)]  = u - v;
                w *= wlen;
            }   
        }
    }

    if(invert)
        for(cd &x: a)
            x /= n;
}

vector<int> multiply(const vector<int> &a, const vector<int> &b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    
    int n = 1;
    while(n < a.size() + b.size())
        n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for(int i = 0; i < n; ++i)
        fa[i] *= fb[i];

    fft(fa, true);

    vector<int> answer(n);
    for(int i = 0; i < n; ++i)
        answer[i] = round(fa[i].real());
    return answer;
}

const int k_N = 1e6 + 7;

int n, m, a[k_N];
vector<int> cnt, cnt2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cnt.resize(m + 1, 0);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }

    cnt2 = multiply(cnt, cnt);

    for(int i = 0; i <= m; ++i){
        if(cnt2[i] && !cnt[i]){
            cout << "NO\n";
            return 0;
        }
    }   

    cout << "YES\n";

    vector<int> answer;
    for(int i = 0; i < n; ++i)
        if(!cnt2[a[i]])
            answer.push_back(a[i]);

    cout << answer.size() << "\n";
    for(int x: answer)
        cout << x << " ";
    cout << "\n";
}