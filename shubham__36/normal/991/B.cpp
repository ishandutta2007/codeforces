#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n],sum =0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    double ex=n*4.5;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    sort(a,a+n);
    int coun=0;
    for(int i=0;i<n && sum < ex;i++){
        sum+=5-a[i];
        coun++;
    }
    cout << coun << endl;
    return 0;
}