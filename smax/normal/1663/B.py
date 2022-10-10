r = int(input())
cutoffs = [1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000]
for x in cutoffs:
    if r < x:
        print(x)
        break