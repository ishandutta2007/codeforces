import sys

king_move = {
    "Right": [0, 1],
    "Left": [0, -1],
    "Up": [-1, 0],
    "Down": [1, 0],
    "Down-Right": [1, 1],
    "Down-Left": [1, -1],
    "Up-Left": [-1, -1],
    "Up-Right": [-1, 1],
}
done = "Done"

def queen_move(p):
    moves = []
    for i in range(8):
        moves.append([])
        for j in range(8):
            moves[i].append(i == p[0] or j == p[1] or abs(i-p[0]) == abs(j-p[1]))
    return moves

def in_board(p):
    return 0 <= p[0] < 8 and 0 <= p[1] < 8

def first_true(start):
    for i in range(8):
        for j in range(8):
            if start[i][j]:
                return i, j
    return None

t = int(input())
for h in range(t):
    start = [[True]*8 for _ in range(8)]
    total = [0, 0]
    queen = [3, 3]
    state = 0
    while True:
        print(f'{queen[0]+1} {queen[1]+1}')
        sys.stdout.flush()
        move = input()
        if move == done:
            break
        move = king_move[move]
        total[0] += move[0]
        total[1] += move[1]
        impos = queen_move(queen)
        for i in range(8):
            for j in range(8):
                if not in_board([i+total[0], j+total[1]]) or impos[i+total[0]][j+total[1]]:
                    start[i][j] = False
        if state == 0:
            target = first_true(start)
            queen[0] = target[0]+total[0]
            state = 1
        elif state == 1:
            if start[target[0]][target[1]]:
                queen[1] = target[1]+total[1]
                state = 2
            else:
                target = first_true(start)
                queen[0] = target[0]+total[0]
        elif state == 2:
            if start[target[0]][target[1]]:
                queen[0] = int((target[0]+total[0]+queen[0])/2)
                queen[1] = target[1]+total[1]
            else:
                target = first_true(start)
                queen[0] = target[0]+total[0]
                state = 1