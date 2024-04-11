# include <iostream>
# include <string>
using namespace std;
int sumof(int sum)
{
    int ans=0;
    while (sum!=0)
    {
        ans+=sum%10;
        sum=sum/10;
    }
    return ans;
}
int main()
{
    int sum=0;
    string s;
    cin>>s;
    
    for (int i=0;i<s.length();i++)
    {
        sum+=s[i]-48;



    }
    if (sum<10 && s.length()==1)
        cout<<0<<endl;
    else if (sum<10)
        cout<<1<<endl;
    else
    {
        int ans=1;
        while (true)
        {
            if (sum<10)
                break;
        sum=sumof(sum);
        
        
        
        
        
        
        
        ans++;
        }
    
    
    
    
    
    
    
    cout<<ans<<endl;
    }

}