k = input()
zeroes = [-1, -1]
five = -1
two = -1
seven = -1
for i in range(len(k)):
    if k[i] == '0':
        zeroes[zeroes.index(min(zeroes))] = i
    elif k[i] == '2':
        two = i
    elif k[i] == '5':
        five = i
    elif k[i] == '7':
        seven = i
if len(k) == 3 and k[:2] == '50' and k[-1] != '5' and k[-1] != '0':
    print(2)
elif k == '5020' or k == '5070':
    print(1)
elif k[-2:] == '25' or k[-2:] == '00' or k[-2:] == '50' or k[-2:] == '75':
    print(0)
elif k[-2:] == '52' or k[-2:] == '05' or k[-2:] == '57':
    print(1)
elif k == '505':
    print(1)
elif k == '500':
    print(0)
elif len(k) != 4 and ((k[:3] == '502' and two == 2) or (k[:3] == '507' and seven == 2)):
    print((len(k)))
elif (len(k) == 4) and (k[:3] == '502' or k[:3] == '507'):
    print(4)
elif k[:2] == '50' and five == 0 and min(zeroes) == -1 and (seven != -1 or two != -1):
    print(2 * len(k) - max(two, seven) - 1)
elif k[:2] == '50' and five == 0 and min(zeroes) != -1 and (seven != -1 or two != -1):
    cnt0 = 0
    for u in range(1, len(k)):
        if k[u] == '0':
            cnt0 += 1
    print(min((len(k) * 2 - zeroes[0] - zeroes[1] - 3), (cnt0 - 1 + len(k))))
else:
    ch = []
    fl = 0
    if min(zeroes) > -1:
        fl = 1
        ch.append(len(k) * 2 - zeroes[0] - zeroes[1] - 3)
    if five != -1 and max(zeroes) > -1:
        fl = 1
        if five < (max(zeroes)):
            ch.append(2 * len(k) - max(zeroes) - five - 3)
        else:
            ch.append(2 * len(k) - max(zeroes) - five - 2)
    if five != -1:
        if two != -1:
            fl = 1
            if two < five:
                ch.append(2 * len(k) - two - five - 3)
            else:
                ch.append(2 * len(k) - two - five - 2)
        if seven != -1:
            fl = 1
            if seven < five:
                ch.append(2 * len(k) - seven - five - 3)
            else:
                ch.append(2 * len(k) - seven - five - 2)
    if fl:
        print(min(ch))
    else:
        print(-1)