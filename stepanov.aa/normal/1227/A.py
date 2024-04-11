def get_lines():
    out = []
    for c in range(int(input())):
        out.append([int(a) for a in input().split()])
    return out


def get_min_max(lines):
    minimum = float('inf')
    maximum = float('-inf')
    for c in lines:
        if c[1] < minimum:
            minimum = c[1]
        if c[0] > maximum:
            maximum = c[0]
    return [minimum, maximum]


for c in range(int(input())):
    a, b = get_min_max(get_lines())
    if b <= a:
        print(0)
    else:
        print(b - a)