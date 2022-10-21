#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
const long double PI = acos(-1.0);
typedef long long ll;

#define swap(a, b) auto tmp = a; a = b, b = tmp;

struct Complex{
    long double x, y;
    Complex(long double _x = 0.0, long double _y = 0.0){
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

const int N = (int)265000;
int n, x;
int a[N], cnt[N];
Complex x1[2*N], x2[2*N];
ll res[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = (a[i] < x) + a[i-1];
    }
    for(int i = 0; i <= n; i++) cnt[a[i]] ++;
    int len1 = n + 1;
    int len = 1;
    while(len < len1 * 2) len *= 2;
    for(int i = 0; i <= n; i++) x1[i] = Complex(cnt[i], 0), x2[i] = Complex(cnt[n-i], 0);
    for(int i = n + 1; i < len; i++) x1[i] = x2[i] = Complex();
    fft(x1, len, 1), fft(x2, len, 1);
    for(int i = 0; i < len; i++) x1[i] = x1[i] * x2[i];
    fft(x1, len, -1);

    res[0] = ((ll)(x1[n].x + 0.5) - n) / 2;
    for(int i = 1; i <= n; i++) res[i] = ((ll)(x1[n + i].x + 0.5));

    for(int i = 0; i <= n; i++) cout << res[i] << " ";


}