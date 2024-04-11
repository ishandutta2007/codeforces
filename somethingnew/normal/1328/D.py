def pos(ls):
    for i in range(-1, len(ls)-1):
        if ls[i] == ls[i+1]:
            return i
    return -2
for i in range(int(input())):
    n = int(input())
    lst = list(map(int, input().split()))
    if len(set(lst)) == 1:
        print(1)
        lll = [1] * n
        print(*lll)
    else:
        if n % 2 == 0:
            lll = [1, 2] * (n//2)
            print(2)
            print(*lll)
        else:
            k = pos(lst)
            if k != -2:
                lll = [1, 2] * (n // 2)
                if k == -1:
                    print(2)
                    print(*lll, 1)
                else:
                    if lll[k] == 1:
                        lll[k] = '1 1'
                    else:
                        lll[k] = '2 2'
                    print(2)
                    print(*lll)
            else:
                print(3)
                lll = [1, 2] * (n // 2)
                print(*lll, 3)