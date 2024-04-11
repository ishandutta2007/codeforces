#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;

unsigned ll doublefactorial(unsigned ll n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * doublefactorial(n - 2);
}

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    bitset<6> b1(n);
    if (b1[5] == 1) {
        sum += 32;
    }
    if (b1[4] == 1) {
        sum += 1;
    }
    if (b1[3] == 1) {
        sum += 4;
    }
    if (b1[2] == 1) {
        sum += 8;
    }
    if (b1[1] == 1) {
        sum += 2;
    }
    if (b1[0] == 1) {
        sum += 16;
    }
    cout << sum << "\n";
}