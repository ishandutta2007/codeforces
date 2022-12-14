# include <iostream>
# include <string>
using namespace std;
int main()
{
    int def1,att1,def2,att2,def3,att3,def4,att4;
    cin>>def1>>att1>>def2>>att2>>def3>>att3>>def4>>att4;
    int team1[2][2]={0};
    team1[0][0]=def1;
    team1[0][1]=att2;
    team1[1][0]=def2;
    team1[1][1]=att1;
    int team2[2][2]={0};
    team2[0][0]=def3;
    team2[0][1]=att4;
    team2[1][0]=def4;
    team2[1][1]=att3;
    if ((team1[0][0]>team2[0][1] && team1[0][1]>team2[0][0] && team1[0][0]>team2[1][1] && team1[0][1]>team2[1][0]) || (team1[1][0]>team2[0][1] && team1[1][1]>team2[0][0] && team1[1][0]>team2[1][1] && team1[1][1]>team2[1][0]) )
        cout<<"Team 1"<<endl;
    else if (((team1[0][0]<team2[0][1] && team1[0][1]<team2[0][0]) || ( team1[0][0]<team2[1][1] && team1[0][1]<team2[1][0])) && ((team1[1][0]<team2[0][1] && team1[1][1]<team2[0][0] )||( team1[1][0]<team2[1][1] && team1[1][1]<team2[1][0])))
        cout<<"Team 2"<<endl;
    else
        cout<<"Draw"<<endl;
}