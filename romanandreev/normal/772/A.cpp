#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdio>

const int NMAX = 2e5;

struct Device {
    double power_usage;
    double battery;

    void Read() {
        scanf("%lf %lf", &power_usage, &battery);
    }

    double TimeOnBattery() const {
        return battery / power_usage;
    }
};

Device devices[NMAX];
int n;
double charger;

bool Can(double t) {
    double need_energy = 0;
    for (int i = 0; i < n; ++i) {
        if (devices[i].TimeOnBattery() < t) {
            need_energy += devices[i].power_usage * (t - devices[i].TimeOnBattery());
        }
    }
    return need_energy < t * charger;
}

int main() {
    scanf("%d %lf", &n, &charger);
    double total_power_usage = 0;
    double total_energy = 0;
    for (int i = 0; i < n; i++) {
        devices[i].Read();
        total_power_usage += devices[i].power_usage;
        total_energy += devices[i].battery;
    }

    if (total_power_usage <= charger) {
        printf("-1\n");
        return 0;
    }

    double l = 0;
    double r = total_energy / (total_power_usage - charger);

    for (int i = 0; i < 200; ++i) {
        double m = (l + r) / 2;
        if (Can(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%.15lf\n", r);
}