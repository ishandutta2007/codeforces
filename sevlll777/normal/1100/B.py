n, m = map(int, input().split())
mass = list(map(int, input().split()))
wuneed = set()
for i in range(1, n+1):
    wuneed.add(i)
bank = dict()
for tutu in mass:
    wuneed.discard(tutu)
    if tutu in bank:
        bank[tutu] += 1
    else:
        bank[tutu] = 1
    if wuneed == set():
        print('1', end='')
        for t in bank:
            bank[t] -= 1
            if bank[t] == 0:
                wuneed.add(t)
    else:
        print('0', end='')