#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

struct Complex{
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0){
        x = _x, y = _y;
    }
    Complex operator - (const Complex &b) const{
        return Complex(x - b.x, y - b.y);
    }
    Complex operator + (const Complex &b) const{
        return Complex(x + b.x, y + b.y);
    }
    Complex operator * (const Complex &b) const{
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

void change(Complex y[], int len){
    int i, j, k;
    for(i = 1, j = len/2; i < len - 1; i++){
        if(i < j){Complex tmp = y[i]; y[i] = y[j], y[j] = tmp;}
        k = len / 2;
        while(j >= k){
            j = j - k;
            k = k / 2;
        }
        if(j < k) j += k;
    }
}

void fft(Complex y[], int len, int on){
    change(y, len);
    for(int h = 2; h <= len; h <<= 1){
        Complex wn(cos(-on*2*PI/h), sin(-on*2*PI/h));
        for(int j = 0; j < len; j += h){
            Complex w(1,0);
            for(int k = j; k < j + h/2; k++){
                Complex u = y[k];
                Complex t = w * y[k + h/2];
                y[k] = u + t;
                y[k + h/2] = u - t;
                w = w * wn;
            }
        }
    }
    if(on == -1){
        for(int i = 0; i < len; i++){
            y[i].x /= len;
        }
    }
}

const int N = 1100000;

int n, len;
string str;
vector<int> a;
Complex x1[N], x2[N];
int ans[N];
vector<int> res;

vector<int> get(int type) {
    for(int i = 0; i < len; i++) x1[i] = x2[i] = Complex(0, 0);
    a = vector<int>(n, 0);
    for(int i = 0; i < n; i++) {
        if(type == 1) a[i] = (str[i] != '?');
        else if(type == 2) a[i] = (str[i] == 'V');
        else a[i] = (str[i] == 'K');
    }
    for(int i = 0; i < n; i++) {
        x1[i] = Complex(a[i], 0);
        x2[n - 1 - i] = Complex(a[i], 0);
    }
    fft(x1, len, 1);
    fft(x2, len, 1);
    for(int i = 0; i < len; i++) x1[i] = x1[i] * x2[i];
    fft(x1, len, -1);
    vector<int> res(n, 0);
    for(int i = 0; i < n; i++) res[i] = (int)(x1[i].x + 0.5);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> str;
        res.clear();
        len = 1;
        while(len < 2 * n) len *= 2;
        auto s = get(1);

        auto a = get(2);
        auto b = get(3);
        fill(ans, ans + n + 1, 0);
        for(int j = n - 2; j >= 0; j--) {
            if(a[j] + b[j] == s[j]) ans[n - 1 - j] = 1;
        }
        ans[n] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = i * 2; j <= n; j += i) if(!ans[j]) ans[i] = 0;
        }
        int cnt = 0;
        for(int j = 1; j <= n; j++) cnt += (ans[j] == 1);
        cout << cnt << '\n';
        for(int j = 1; j <= n; j++) if(ans[j]) cout << j << " ";
        cout << '\n';

    }


}