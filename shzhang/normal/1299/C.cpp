#include <cstdio>
#include <vector>

using namespace std;

#define ll long long
ll seq[1000005]; int n;
double ans[1000005];

long double slope(ll x1, ll y1, ll x2, ll y2)
{
    //printf("%lld %lld %lld %lld\n", x1, y1, x2, y2);
    return (long double)(y2 - y1) / (long double)(x2 - x1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", seq + i);
        seq[i] += seq[i-1];
    }
    if (n == 1) {
        printf("%lld", seq[1]); return 0;
    }
    vector<int> hull;
    for (int i = 0; i <= n; i++) {
        while (hull.size() >= 2 && slope(hull[hull.size()-1], seq[hull[hull.size()-1]], i, seq[i]) <
                                   slope(hull[hull.size()-2], seq[hull[hull.size()-2]], i, seq[i])) {
                                       hull.pop_back();
        }
        hull.push_back(i);
    }
    //for (int i = 0; i < hull.size(); i++) printf("%d\n", hull[i]);
    for (int i = 0; i + 1 < hull.size(); i++) {
        ll sum = seq[hull[i+1]] - seq[hull[i]];
        for (int j = hull[i] + 1; j <= hull[i+1]; j++) {
            ans[j] = (double)sum / (double)(hull[i+1] - hull[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%.10f\n", ans[i]);
    }
    return 0;
}