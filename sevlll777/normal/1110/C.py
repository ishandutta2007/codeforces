for i in range(int(input())):
    n = int(input())
    lol = str(bin(n))[2:]
    if '0' in lol:
        print(2 ** (len(lol)) - 1)
    else:
        fl = 0
        hom = (2 ** len(lol)) - 1
        for z in range(3, int(hom**0.5) + 1):
            if hom % z == 0:
                print(hom // z)
                fl = 1
                break
        if not fl:
            print(1)