#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    long long int r;
    double sum=0;
    cin >> n >> r;
    long long int a[(1 << n)];
    for(long long int i=0;i<(1 << n);i++){
        cin >> a[i];
        sum+=a[i];
    }
    cout << (sum/(1 << n)) << endl;
    long long int temp;
    for(long long int i=0;i<r;i++){
        cin >> temp;
        sum-=a[temp];
        cin >> a[temp];
        sum+=a[temp];
        cout <<setprecision(7) <<(sum/(1 << n)) << endl;
    }
    return 0;
}