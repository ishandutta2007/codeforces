#include <iostream>
using namespace std;

int my_hp, my_atk, my_def;
int mo_hp, mo_atk, mo_def;
int buy_h, buy_a, buy_d;

int main(){
    cin >> my_hp >> my_atk >> my_def;
    cin >> mo_hp >> mo_atk >> mo_def;
    cin >> buy_h >> buy_a >> buy_d;

    int minc = 0;
    if(my_atk <= mo_def) minc = buy_a * (1 + mo_def - my_atk);

    int ans = 1 << 30;

    for(int db = 0; db <= max(0, mo_atk - my_def); db++){
        if((my_def + db) >= mo_atk) ans = min(ans, db * buy_d);
        else{
            int dmg_to_me = mo_atk - my_def - db;
            
            for(int dmg_to_mo = max(1, my_atk - mo_def); true; dmg_to_mo++){
                int cur_dmg = max(1, my_atk - mo_def);
                int turns = (mo_hp + dmg_to_mo - 1) / dmg_to_mo;
                int hp_to_buy = max(0, dmg_to_me * turns - my_hp + 1);
                ans = min(ans, (dmg_to_mo - cur_dmg) * buy_a + hp_to_buy * buy_h + db * buy_d);
        
                if(dmg_to_mo > mo_hp) break;
            }
        }
    }

    cout << ans + minc << endl;
    return 0;
}