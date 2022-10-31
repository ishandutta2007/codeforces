
for c in range(int(input())):
    a = int(input())
    if a < 4:
        print(4 - a)
    else:
        if a%2 == 0:
            print(0)
        else:
            print(1)