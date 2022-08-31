#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n,ans=0;
    cin >> n;
    string a[n],b[n];
    int count1[9]={0},count2[9]={0};
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]=="M") count1[0]++;
        else if(a[i]=="L") count1[1]++;
        else if(a[i]=="S") count1[2]++;
        else if(a[i]=="XL") count1[3]++;
        else if(a[i]=="XS") count1[4]++;
        else if(a[i]=="XXL") count1[5]++;
        else if(a[i]=="XXS") count1[6]++;
        else if(a[i]=="XXXL") count1[7]++;
        else if(a[i]=="XXXS") count1[8]++;
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(b[i]=="M") count2[0]++;
        else if(b[i]=="L") count2[1]++;
        else if(b[i]=="S") count2[2]++;
        else if(b[i]=="XL") count2[3]++;
        else if(b[i]=="XS") count2[4]++;
        else if(b[i]=="XXL") count2[5]++;
        else if(b[i]=="XXS") count2[6]++;
        else if(b[i]=="XXXL") count2[7]++;
        else if(b[i]=="XXXS") count2[8]++;
    }
    ans+=abs(count1[3]-count2[3]);
    ans+=abs(count1[5]-count2[5]);
    ans+=abs(count1[7]-count2[7]);
    ans+=max(max(abs(count1[0]-count2[0]),abs(count1[1]-count2[1])),abs(count1[2]-count2[2]));
    cout << ans << endl;
    return 0;
}