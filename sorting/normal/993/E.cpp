#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 3;
const double PI = acos(-1);

template<class T>
class Fast_Complex{
private:
    T r, i;
public:
    Fast_Complex(T _r = 0, T _i = 0){
        r = _r, i = _i;
    }
    T real()const{
        return r;
    }
    friend Fast_Complex operator+(const Fast_Complex &lvalue, const Fast_Complex &rvalue){
        return {lvalue.r + rvalue.r, lvalue.i + rvalue.i};
    }
    friend Fast_Complex operator-(const Fast_Complex &lvalue, const Fast_Complex &rvalue){
        return {lvalue.r - rvalue.r, lvalue.i - rvalue.i};
    }
    friend Fast_Complex operator*(const Fast_Complex &lvalue, const Fast_Complex &rvalue){
        return {lvalue.r * rvalue.r - lvalue.i * rvalue.i, lvalue.r * rvalue.i + lvalue.i * rvalue.r};
    }
    friend Fast_Complex operator/(const Fast_Complex &lvalue, const T &rvalue){
        return {lvalue.r / rvalue, lvalue.i / rvalue};
    }
};

typedef Fast_Complex<long double> cd;

void fft(vector<cd> &a, bool invert){
    int n = a.size();
    for(int i = 1, j = 0; i < n; ++i){
        int bit = (n >> 1);
        for(; bit & j; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if(i < j)
            swap(a[i], a[j]);
    }

    for(int len = 2; len <= n; len <<= 1){
        double angle = (double)2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(angle), sin(angle));

        for(int i = 0; i < n; i += len){
            cd w(1);
            for(int j = 0; j < (len >> 1); ++j){
                cd u = a[i + j], v = a[i + j + (len >> 1)] * w;

                a[i + j] = u + v;
                a[i + j + (len >> 1)] = u - v;

                w = w * wlen;
            }
        }
    }

    if(invert){
        for(cd &x: a)
            x = x / n;
    }
}

vector<long long> multiply(const vector<long long> &a, const vector<long long> &b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    int n = 1;
    while(n < a.size() + b.size())
        n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for(int i = 0; i < n; ++i)
        fa[i] = fa[i] * fb[i];

    fft(fa, true);

    vector<long long> answer;
    answer.resize(n);
    for(int i = 0; i < n; ++i)
        answer[i] = round(fa[i].real());

    return answer;
}

int a[k_N];
long long answer[k_N];
int n, x;

void divide_and_conquer(int l, int r){
    if(l == r){
        answer[a[l] < x]++;
        return;
    }

    int mid = (l + r) >> 1;

    vector<long long> l_cnt, r_cnt;
    l_cnt.clear();
    r_cnt.clear();

    for(int i = mid; i >= l; --i){
        if(i == mid){
            if(a[i] < x){
                l_cnt.push_back(0);
                l_cnt.push_back(1);
            }
            else
                l_cnt.push_back(1);

            continue;
        }

        if(a[i] < x)
            l_cnt.push_back(1);
        else
            l_cnt.back() += 1;
    }

    for(int i = mid + 1; i <= r; ++i){
        if(i == mid + 1){
            if(a[i] < x){
                r_cnt.push_back(0);
                r_cnt.push_back(1);
            }
            else
                r_cnt.push_back(1);
        
            continue;
        }

        if(a[i] < x)
            r_cnt.push_back(1);
        else
            r_cnt.back() += 1;
    }

    vector<long long> add;
    add = multiply(l_cnt, r_cnt);

    for(int i = 0; i < min((int)add.size(), n + 1); ++i)
        answer[i] += add[i];

    divide_and_conquer(l, mid);
    divide_and_conquer(mid + 1, r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    divide_and_conquer(1, n);

    for(int i = 0; i <= n; ++i)
        cout << answer[i] << " ";
    cout << "\n";
}