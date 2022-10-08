    import java.util.*;
    import java.util.Map.Entry;
     
    public class B {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int n = in.nextInt();
            int m = in.nextInt();
            ArrayDeque<Integer> q = new ArrayDeque<>();
            HashMap<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                q.add(x);
                map.put(x, 0);
            }
            ArrayList<Integer> list = new ArrayList<>();
            while (!q.isEmpty() && list.size() < m) {
                int x = q.poll();
                if (map.get(x) != 0) {
                    list.add(x);
                }
                if (!map.containsKey(x + 1)) {
                    q.add(x + 1);
                    map.put(x + 1, map.get(x) + 1);
                }
                if (!map.containsKey(x - 1)) {
                    q.add(x - 1);
                    map.put(x - 1, map.get(x) + 1);
                }
            }
            long sum = 0;
            StringBuilder sb = new StringBuilder();
            for (int i : list) {
                sum += map.get(i);
                sb.append(i + " ");
            }
            System.out.println(sum);
            System.out.println(sb.toString());
     
        }
    }