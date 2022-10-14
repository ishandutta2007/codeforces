from math import gcd
n = int(input())
for t in range(n):
    ang = int(input())
    if ang == 179:
        print(360)
    elif ang == 178:
        print(180)
    elif ang == 90:
        print(4)
    else:
        z = gcd(ang, 180)
        if 180%(180-ang) == 0:
            print(360//z)
        else:
            print(180//z)