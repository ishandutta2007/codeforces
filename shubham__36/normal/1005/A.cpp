#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n,temp,num=1,j=0;
    cin >> n;
    int a[n],tem[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    temp=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<=temp){
            num++;
            tem[j]=temp;
            j++;
        }
        temp=a[i];
    }
    tem[j]=temp;
            j++;
    cout << num << endl;
    for(int i=0;i<j;i++){
        cout << tem[i] << " ";
    }
    return 0;
}