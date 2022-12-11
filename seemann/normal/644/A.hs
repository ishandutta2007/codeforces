import Data.List

rowToString [] = ""
rowToString (x : xs) = (show x) ++ " " ++ (rowToString xs)
tableToString [] = ""
tableToString (r : rs) = (rowToString r) ++ ("\n") ++( tableToString rs)

up b = div (b + 1) 2
down b = div b 2
build a n m b | a == 0 = []
              | otherwise = ((map (max 0) . concat . transpose $ ([take (up b) [n, n - 2..], take (down b) [m, m - 2..]])): build (a - 1) (m - 2 * down(b)) (n - 2 * up(b)) b)
main = do
    [n, a, b] <- fmap (map  read . words) getLine
    putStr .tableToString $ if (n > a * b) then [[(-1)]] else (build a n (n - 1) b)