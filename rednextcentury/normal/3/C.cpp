# include <iostream>
using namespace std;
char a[3][3];
bool win(char x)
{
    if ((a[0][0]==x && a[0][1]==x && a[0][2]==x) || (a[0][0]==x && a[1][1]==x && a[2][2]==x) || (a[0][0]==x && a[1][0]==x && a[2][0]==x) || (a[1][0]==x && a[1][1]==x && a[1][2]==x) || (a[2][0]==x && a[2][1]==x && a[2][2]==x) || (a[2][0]==x && a[1][1]==x && a[0][2]==x) || (a[0][1]==x && a[1][1]==x && a[2][1]==x) || (a[0][2]==x && a[1][2]==x && a[2][2]==x))
        return 1;
    else
        return 0;
}
int main()
{
    int xs=0;
    int os=0;
    for (int i=0;i<3;i++)
    {
        for (int x=0;x<3;x++)
        {
            cin>>a[i][x];
            if (a[i][x]=='X')
                xs++;
            else if(a[i][x]=='0')
                os++;
        }
    }
    if (os>xs || xs>os+1 || (win('0') && win('X')) || (win('0') && xs>os) || (win('X') && os==xs))
        cout<<"illegal"<<endl;
    else if (xs==5 && os==4 && win('0')==0 && win('X')==0)
        cout<<"draw"<<endl;
    else if (win('X'))
        cout<<"the first player won"<<endl;
    else if (win('0'))
        cout<<"the second player won"<<endl;
    else if (xs>os)
        cout<<"second"<<endl;
    else if (os==xs)
        cout<<"first"<<endl;



}