#include <iostream>
using namespace std;
int t, n;
string s1, s2, s3;

void Process() {
    cin >> n >> s1 >> s2 >> s3;
    string ans = "";
    int i=0, j=0, w=0;
    while (i<n*2 && j<n*2 && w<n*2) {
        char c = (s1[i] + s2[j] + s3[w] - '0'*3 >= 2) + '0';
        if (s1[i] == c) ++i;
        if (s2[j] == c) ++j;
        if (s3[w] == c) ++w;
        ans += c;
    }
    if (i>=j || i>=w) while (i<n*2) ans += s1[i++];
    if (j>i || j>=w) while (j<n*2) ans += s2[j++];
    if (w>i || w>j) while (w<n*2) ans += s3[w++];
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Process();

    }
}