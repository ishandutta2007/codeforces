def read_seq(v):
    seq = []
    for i in range(2 * v):
        s = input().split()
        if len(s) == 2:
            s[1] = int(s[1])
        seq.append(s)
    return seq


def solve():
    n = int(input())
    pos = [-1] * (2 * n)
    stack = []
    seq = read_seq(n)
    for i, act in enumerate(seq):
        if act[0] == '+':
            stack.append(i)
        else:
            if not stack:
                return None
            else:
                v = stack.pop()
                pos[v] = act[1]
    if stack:
        return None

    stack = []
    for i, act in enumerate(seq):
        if act[0] == '+':
            if stack and stack[-1] < pos[i]:
                return None
            else:
                stack.append(pos[i])
        else:
            stack.pop()

    return [x for x in pos if x != -1]


def main():
    res = solve()
    if res:
        print('YES')
        print(' '.join(map(str, res)))
    else:
        print('NO')


if __name__ == '__main__':
    main()